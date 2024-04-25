# example_interface.py
from catkit.example import add

def subtract(a, b):
    """A Python function that subtracts two numbers."""
    return a - b

def calculate_sum(numbers):
    """A Python function that uses the C++ add function to sum a list of numbers."""
    total = 0
    for num in numbers:
        total = add(total, num)
    return total