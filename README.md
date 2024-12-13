# :fast_forward: Push Swap :repeat: : Implementing the Turk Algorithm

<p align="center">
<img src="push_swap_visualization.gif" alt="Push swap visualization sorting 500 random numbers">
<p/>

This project implements the **Turk Algorithm** https://medium.com/@ayogun/push-swap-c1f5d2d41e97 to sort a stack (`a`) using an auxiliary stack (`b`). The algorithm applies a set of predefined operations to manipulate the stacks and achieve a sorted state for `a`. It also contains a `checker` useful to validate the instructions provided by the main program `push_swap`.

## :zap: Features :zap:
- Sorting a stack using an auxiliary stack.
- Implementation of stack manipulation rules with minimal computational overhead.
- Efficient sorting leveraging constraints on operations (for a stack of 500 numbers the program succesfully sorts it in less than 5500 operations).

## Rules and Operations

The following operations are implemented to manipulate the stacks:

### Push Operations :fast_forward:
- **`pa` (push a):** Moves the first element of stack `b` to the top of stack `a`. Does nothing if `b` is empty.
- **`pb` (push b):** Moves the first element of stack `a` to the top of stack `b`. Does nothing if `a` is empty.

### Swap Operations :repeat:
- **`sa` (swap a):** Swaps the first two elements of stack `a`. Does nothing if there are fewer than two elements.
- **`sb` (swap b):** Swaps the first two elements of stack `b`. Does nothing if there are fewer than two elements.
- **`ss`:** Performs `sa` and `sb` simultaneously.

### Rotate Operations :arrows_clockwise:
- **`ra` (rotate a):** Shifts all elements of stack `a` upwards by one position. The first element becomes the last.
- **`rb` (rotate b):** Shifts all elements of stack `b` upwards by one position. The first element becomes the last.
- **`rr`:** Performs `ra` and `rb` simultaneously.

### Reverse Rotate Operations 🔄:
- **`rra` (reverse rotate a):** Shifts all elements of stack `a` downwards by one position. The last element becomes the first.
- **`rrb` (reverse rotate b):** Shifts all elements of stack `b` downwards by one position. The last element becomes the first.
- **`rrr`:** Performs `rra` and `rrb` simultaneously.

## :rocket: How to Build and Run (Linux and UNIX) :rocket:
1. Clone the repository.
   ```bash
   git clone https://github.com/your-username/push_swap.git
   ```
2. Navigate to the proyect directory.
   ```bash
   cd push_swap
   ```
3. Compile the program.
   ```bash
   make
   ```
4. Run the program, providing the stack to be sorted as arguments, e.g.
   ```bash
   ./push_swap 4 3 2 1
   ```
## :rocket: Use the checker program :rocket:
1. Compile the checker.
   ```bash
   make bonus
   ```
2. Run the executable providing the stack to be sorted as arguments, e.g.
   ```bash
   ./checker 4 3 2 1
   ```
3. Insert the instructions as a list and when finished press `Ctrl + d` (the programm will be listening to stdin). If `OK` is displayed the stack has been sorted, if `KO` is displayed then the instructions provided do not sort the stack. If the arguments are other than numbers, if a number is repeated or if the instructions are not valid then an `Error` message will be displayed.
