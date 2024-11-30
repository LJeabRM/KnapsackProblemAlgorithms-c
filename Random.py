import random

# Set random seed for reproducibility
random.seed(42)

# Define parameters
n = 1000  # Number of items
max_weight = 1000  # Maximum weight 
max_value = 4000  # Maximum value 

# Generate random weights and values for 500 items
items = [(random.randint(1, max_weight), random.randint(1, max_value)) for _ in range(n)]

# Maximum weight capacity for the knapsack (can be large enough)
max_capacity = 40000

# Prepare the output in the format as requested
output_data = [f"{n}"]  # First line with number of items
for weight, value in items:
    output_data.append(f"{weight} {value}")
output_data.append(str(max_capacity))  # Last line with maximum capacity

# Save to a file
file_path = "knapsack1000.txt"  
with open(file_path, "w") as file:
    file.write("\n".join(output_data))


file_path
