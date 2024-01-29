"""
Usage: fetch_description.py [problem_number]
  - problem_number: The number of the problem on Project Euler.

This script fetches the description of the specified problem number
from Project Euler and prints it to the standard output.

Example:
  $ python3 fetch_description.py 1
"""
import urllib.request
import sys
from bs4 import BeautifulSoup
import re

# Mapping of LaTeX symbols to their Unicode equivalents
latex_to_unicode = {
    '\\ne': '≠',
    '\\leq': '≤',
    '\\geq': '≥',
    '\\times': '×',
    '\\div': '÷',
    '\\pm': '±',
    '\\infty': '∞',
    '\\to': '→',
    '\\Rightarrow': '⇒',
    '\\subset': '⊂',
    '\\supset': '⊃',
    '\\cup': '∪',
    '\\cap': '∩',
    '\\sqrt': '√',
    '\\int': '∫',
    '\\sum': '∑',
    '\\alpha': 'α',
    '\\beta': 'β',
    '\\gamma': 'γ',
    '\\delta': 'δ',
    '\\epsilon': 'ε',
    '\\theta': 'θ',
    '\\lambda': 'λ',
    '\\mu': 'μ',
    '\\sigma': 'σ',
    '\\omega': 'ω',
}

def fetch_problem_description(problem_number):
    url = f"https://projecteuler.net/problem={problem_number}"
    try:
        with urllib.request.urlopen(url) as response:
            html_content = response.read().decode('utf-8')
            soup = BeautifulSoup(html_content, 'html.parser')
            problem_content = soup.find('div', class_='problem_content')
            if problem_content:
                # Get text content within the <div class="problem_content"> tag
                problem_description = problem_content.get_text(separator='\n')
                # Parse LaTeX expressions and replace LaTeX symbols with Unicode characters
                problem_description = parse_latex(problem_description)
                return problem_description.strip()
            else:
                return "Failed to find problem description."
    except Exception as e:
        return f"Failed to fetch problem description: {e}"

def parse_latex(text):
    # Remove $ symbols around LaTeX statements
    text = re.sub(r'\$(.*?)\$', lambda match: match.group(1), text)
    # Replace LaTeX symbols with their Unicode equivalents using regular expressions
    for latex, unicode_symbol in latex_to_unicode.items():
        text = re.sub(re.escape(latex), unicode_symbol, text)
    return text

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python fetch_description.py [problem_number]")
        sys.exit(1)

    problem_number = sys.argv[1]
    problem_description = fetch_problem_description(problem_number)
    print(problem_description)
