import java.util.Scanner;

class STACK {
    private int[] stack;
    private int top;
    private int capacity;

    // Constructor to initialize stack
    public STACK(int size) {
        stack = new int[size];
        capacity = size;
        top = -1;
    }

    // Push an element onto the stack
    public void push(int element) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push " + element);
            return;
        }
        stack[++top] = element;
        System.out.println("Pushed element: " + element);
    }

    // Pop an element from the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Nothing to pop.");
            return -1;
        }
        System.out.println("Popped element: " + stack[top]);
        return stack[top--];
    }

    // Peek at the top element without removing it
    public int peek() {
        if (!isEmpty()) {
            return stack[top];
        }
        System.out.println("Stack is empty. Nothing to peek.");
        return -1;
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    public boolean isFull() {
        return top == capacity - 1;
    }

    // Display the stack elements
    public void displayStack() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.print("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter stack size: ");
        int size = scanner.nextInt();
        STACK stack = new STACK(size);

        boolean exit = false;

        while (!exit) {
            System.out.println("\nChoose an operation:");
            System.out.println("1. Push Element");
            System.out.println("2. Pop Element");
            System.out.println("3. Peek top Element");
            System.out.println("4. Check if Stack is Empty");
            System.out.println("5. Check if Stack is Full");
            System.out.println("6. Display Stack");
            System.out.println("7. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter element to push: ");
                    int element = scanner.nextInt();
                    stack.push(element);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    int peekElement = stack.peek();
                    if (peekElement != -1) {
                        System.out.println("Top element is: " + peekElement);
                    }
                    break;
                case 4:
                    System.out.println("Stack is empty: " + stack.isEmpty());
                    break;
                case 5:
                    System.out.println("Stack is full: " + stack.isFull());
                    break;
                case 6:
                    stack.displayStack();
                    break;
                case 7:
                    exit = true;
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }

        scanner.close();
    }
}



