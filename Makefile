# Colors using printf for ANSI escape codes
YELLOW := $(shell printf "\033[1;33m")
GREEN := $(shell printf "\033[1;32m")
CYAN := $(shell printf "\033[1;36m")
RED := $(shell printf "\033[1;31m")
RESET := $(shell printf "\033[0m")

# Variables
DOCKER_COMPOSE_FILE=docker-compose.yml
SRC_DIR=./src

# Docker Variables
DOCKER_IMAGE_NAME=my_ros2_image
DOCKER_CONTAINER_NAME=my_ros2_container

# Local linting tools paths
CPP_LINTER=cppcheck
PYTHON_LINTER=flake8

# Default target
.DEFAULT_GOAL := help

# Mark targets as PHONY (always run, even if a file with the same name exists)
.PHONY: help dc-build dc-up dc-down dc-logs dc-lint_cpp dc-lint_py dc-test dc-clean nuc-deploy nuc-build nuc-start nuc-stop lint_cpp lint_py

## Show help
help:
	@echo ''
	@echo 'Usage:'
	@echo ' make <target>'
	@echo ''
	@echo 'Development Rules:'
	@echo ' ------------------'
	@echo ' $(CYAN)make dc-build$(RESET)        Build Docker containers'
	@echo ' $(CYAN)make dc-up$(RESET)          Start Docker containers'
	@echo ' $(CYAN)make dc-down$(RESET)        Stop and remove Docker containers'
	@echo ' $(CYAN)make dc-logs$(RESET)        Show Docker container logs'
	@echo ' $(CYAN)make dc-test$(RESET)        Run tests inside Docker'
	@echo ' $(CYAN)make dc-clean$(RESET)       Clean up Docker images and containers'
	@echo ''
	@echo ' $(GREEN)make lint-cpp$(RESET)       Run local C++ linting'
	@echo ' $(GREEN)make lint-py$(RESET)        Run local Python linting'
	@echo ''
	@echo 'CI/CD Docker Linting Rules:'
	@echo ' -------------------------'
	@echo ' $(CYAN)make dc-lint_cpp$(RESET)    Run C++ linting inside Docker'
	@echo ' $(CYAN)make dc-lint_py$(RESET)     Run Python linting inside Docker'
	@echo ''
	@echo 'NUC Rules:'
	@echo ' ---------------------'
	@echo ' $(RED)make nuc-deploy$(RESET)     Deploy files to NUC and run deployment script'
	@echo ''
	@echo ' $(RED)make nuc-build$(RESET)      Build ROS 2 project on NUC'
	@echo ' $(RED)make nuc-start$(RESET)      Start ROS 2 project on NUC'
	@echo ' $(RED)make nuc-stop$(RESET)       Stop ROS 2 project on NUC'
	@echo ''

## Build Docker containers
dc-build:
	docker-compose -f $(DOCKER_COMPOSE_FILE) build

## Start Docker containers
dc-up:
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

## Stop and remove Docker containers
dc-down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

## Show Docker container logs
dc-logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f

## Run C++ linting inside Docker
dc-lint_cpp:
	docker-compose -f $(DOCKER_COMPOSE_FILE) run --rm app bash -c "find /workspace/src -name '*.cpp' -o -name '*.hpp' | xargs cpplint > /workspace/lint_results_cpp.txt"

## Run Python linting inside Docker
dc-lint_py:
	docker-compose -f $(DOCKER_COMPOSE_FILE) run --rm app flake8 /workspace/src > /workspace/lint_results_py.txt"

## Run tests inside Docker
dc-test:
	docker-compose -f $(DOCKER_COMPOSE_FILE) run --rm app bash -c "colcon test"

## Clean up Docker images and containers
dc-clean:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --rmi all
	rm -rf build install log

## Deploy to NUC
nuc-deploy:
	rsync -avz --exclude='*.git' --exclude='build/' --exclude='install/' --exclude='log/' ./ $(NUC_USER)@$(NUC_HOST):$(NUC_DEPLOY_PATH)
	ssh $(NUC_USER)@$(NUC_HOST) "cd $(NUC_DEPLOY_PATH) && ./scripts/deploy.sh"

## Build ROS 2 project on NUC
nuc-build:
	ssh $(NUC_USER)@$(NUC_HOST) "source $(ROS2_WORKSPACE_SETUP_PATH) && colcon build --symlink-install"

## Start ROS 2 project on NUC
nuc-start:
	ssh $(NUC_USER)@$(NUC_HOST) "source $(ROS2_WORKSPACE_SETUP_PATH) && ros2 launch robot_control.launch.py"

## Stop ROS 2 project on NUC
nuc-stop:
	ssh $(NUC_USER)@$(NUC_HOST) "ros2 lifecycle set /robot_control_node shutdown"

## Run local C++ linting
lint-cpp:
	find $(SRC_DIR) -name '*.cpp' -o -name '*.hpp' | xargs $(CPP_LINTER) --enable=all

## Run local Python linting
lint-py:
	$(PYTHON_LINTER) $(SRC_DIR)
