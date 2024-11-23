# Push Swap: Implementing the Turk Algorithm

This project implements the **Turk Algorithm** to sort a stack (`a`) using an auxiliary stack (`b`). The algorithm applies a set of predefined operations to manipulate the stacks and achieve a sorted state for `a`.

## Features
- Sorting a stack using an auxiliary stack.
- Implementation of stack manipulation rules with minimal computational overhead.
- Efficient sorting leveraging constraints on operations.

## Rules and Operations

The following operations are implemented to manipulate the stacks:

### Swap Operations
- **`sa` (swap a):** Swaps the first two elements of stack `a`. Does nothing if there are fewer than two elements.
- **`sb` (swap b):** Swaps the first two elements of stack `b`. Does nothing if there are fewer than two elements.
- **`ss`:** Performs `sa` and `sb` simultaneously.

### Push Operations
- **`pa` (push a):** Moves the first element of stack `b` to the top of stack `a`. Does nothing if `b` is empty.
- **`pb` (push b):** Moves the first element of stack `a` to the top of stack `b`. Does nothing if `a` is empty.

### Rotate Operations
- **`ra` (rotate a):** Shifts all elements of stack `a` upwards by one position. The first element becomes the last.
- **`rb` (rotate b):** Shifts all elements of stack `b` upwards by one position. The first element becomes the last.
- **`rr`:** Performs `ra` and `rb` simultaneously.

### Reverse Rotate Operations
- **`rra` (reverse rotate a):** Shifts all elements of stack `a` downwards by one position. The last element becomes the first.
- **`rrb` (reverse rotate b):** Shifts all elements of stack `b` downwards by one position. The last element becomes the first.
- **`rrr`:** Performs `rra` and `rrb` simultaneously.

## How to Build and Run
1. Clone the repository.
   ```bash
   git clone https://github.com/your-username/push_swap.git
   ```
2. Navigate to the proyect directory.
   `cd push_swap`
3. Compile the program.
   ```
