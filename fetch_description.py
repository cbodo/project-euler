import sys
import re
import requests
from bs4 import BeautifulSoup
from sympy import latex

def fetch_description(problem_number):
    url = f"https://projecteuler.net/problem={problem_number}"
    try:
        response = requests.get(url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        problem_content = soup.find(class_='problem_content')
        if problem_content:
            # Extract text from problem content
            problem_text = problem_content.get_text()
            # Convert LaTeX to plain text
            problem_text = latex_to_plain_text(problem_text)
            return problem_text.strip()
        else:
            return None
    except Exception as e:
        print(f"Failed to fetch problem description: {e}")
        return None

def latex_to_plain_text(text):
    # Remove LaTeX environment tags
    text = re.sub(r'\\{0,1}begin\{[^}]+\}|\\{0,1}end\{[^}]+\}', '', text)
    # Replace LaTeX inline math expressions with plain text
    text = re.sub(r'\$(.*?)\$', lambda match: match.group(1), text)
    # Replace LaTeX newline commands with actual newline characters
    text = text.replace('\\', '\n')
    # Remove ampersand characters
    text = text.replace('&', '')
    return text

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python fetch_description.py [problem_number]")
        sys.exit(1)
    problem_number = sys.argv[1]
    problem_description = fetch_description(problem_number)
    if problem_description:
        print(problem_description)
    else:
        print("Failed to fetch problem description.")
