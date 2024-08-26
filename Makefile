# Makefile for ROS 2 Docker project using docker-compose

# Colors using printf for ANSI escape codes
YELLOW := $(shell printf "\033[1;33m")
GREEN := $(shell printf "\033[1;32m")
RESET := $(shell printf "\033[0m")

TARGET_MAX_CHAR_NUM=20

# Variables
PROJECT_NAME=my_ros2_project
DOCKER_COMPOSE_FILE=docker-compose.yml

# Default target
.DEFAULT_GOAL := help

# Mark targets as PHONY (always run, even if a file with the same name exists)
.PHONY: help build up down logs lint_cpp lint_py test clean

## Show help
help:
	@echo ''
	@echo 'Usage:'
	@echo ' $(YELLOW)make$(RESET) $(GREEN)<target>$(RESET)'
	@echo ''
	@echo 'Targets:'
	@awk 'BEGIN { \
		green = "$(GREEN)"; \
		yellow = "$(YELLOW)"; \
		reset = "$(RESET)"; \
		targetWidth = $(TARGET_MAX_CHAR_NUM); \
	} \
	/^[a-zA-Z\-_0-9]+:/ { \
		helpMessage = match(lastLine, /^## (.*)/); \
		if (helpMessage) { \
			helpCommand = substr($$1, 0, index($$1, ":")-1); \
			helpMessage = substr(lastLine, RSTART + 3, RLENGTH); \
			printf " %s%-*s%s %s%s%s\n", yellow, targetWidth, helpCommand, reset, green, helpMessage, reset; \
		} \
	} \
	{ lastLine = $$0 }' $(MAKEFILE_LIST)

## Build the Docker containers
build:
	docker-compose -f $(DOCKER_COMPOSE_FILE) build

## Run the Docker containers
up:
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

## Stop and remove the Docker containers
down:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

## Show logs from the Docker containers
logs:
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs -f

## Run C++ linting (using cpplint)
lint_cpp:
	docker-compose -f $(DOCKER_COMPOSE_FILE) run --rm app bash -c "find /workspace/src -name '*.cpp' -o -name '*.hpp' | xargs cpplint"

## Run Python linting (using flake8)
lint_py:
	docker-compose -f $(DOCKER_COMPOSE_FILE) run --rm app flake8 /workspace/src

## Run tests inside the Docker containers
test:
	docker-compose -f $(DOCKER_COMPOSE_FILE) exec app bash -c "colcon test"

## Clean up Docker images
clean:
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --rmi all
