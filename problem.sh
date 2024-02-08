#!/bin/bash

# Usage: ./problem.sh [problem_number]
#   - problem_number: The number of the problem on Project Euler.
#
# This script creates a directory for the specified problem number,
# fetches the problem description from Project Euler, updates the
# C++ template file with the problem number and description, and opens
# the file in Visual Studio Code for editing, and opens the web page.

# Get problem number from command-line argument
problem_number=$1

# Ensure problem number is provided
if [ -z "$problem_number" ]; then
    echo "Error: Problem number not provided."
    exit 1
fi

# Fetch problem title from Project Euler website
problem_title=$(curl -s "https://projecteuler.net/problem=$problem_number" | grep -o '<title>.*</title>' | sed 's/<title>\(.*\)<\/title>/\1/')

if [ -z "$problem_title" ]; then
    echo "Error: Failed to fetch problem title."
    exit 1
fi

# Check if directory already exists
if [ -d "problem_$problem_number" ]; then
    echo "Directory 'problem_$problem_number' already exists. Updating..."
else
    # Create directory
    if mkdir "problem_$problem_number"; then
        echo "Created directory 'problem_$problem_number'."
    else
        echo "Error: Failed to create directory."
        exit 1
    fi
fi

# Change directory
if cd "problem_$problem_number"; then
    # Fetch problem description using Python script
    problem_description=$(python3 ../fetch_description.py $problem_number)
    if [ -z "$problem_description" ]; then
        echo "Error: Failed to fetch problem description."
        exit 1
    fi

    # Check if .cpp file already exists
    if [ -f "problem_$problem_number.cpp" ]; then
        echo "File 'problem_$problem_number.cpp' already exists. Updating..."
    else
        # Copy template.cpp to create new .cpp file
        cp ../template.cpp "problem_$problem_number.cpp"
    fi

    echo "Problem Description: $problem_description"


    # Replace placeholders in the .cpp file
    sed -i '' "s/{{PROBLEM_NUMBER}}/$problem_number/g" "problem_$problem_number.cpp"
    escaped_description=$(echo "$problem_description" | sed 's/$/\\n/' | sed 's/\//\\\//g' | tr -d '\n')  # Escape forward slashes and remove newlines
    sed -i '' "s/{{DESCRIPTION}}/$escaped_description/" "problem_$problem_number.cpp"
    updated_title=$(echo "$problem_title" | sed -E 's/#[0-9]{1,3} (.*) - Project Euler/\1/')
    sed -i '' "s/{{TITLE}}/$updated_title/" "problem_$problem_number.cpp"

    # Optional: Open the file in your preferred text editor
    # open -a "Visual Studio Code" "problem_$problem_number.cpp"  # Use your preferred text editor

else
    echo "Error: Failed to change directory."
    exit 1
fi

# Construct the URL
url="https://projecteuler.net/problem=$problem_number"

# Open the URL in the default web browser
if command -v xdg-open &>/dev/null; then
    xdg-open "$url"   # Linux
elif command -v open &>/dev/null; then
    open "$url"       # macOS
else
    echo "Error: Unable to open URL. Please open '$url' manually."
    exit 1
fi
