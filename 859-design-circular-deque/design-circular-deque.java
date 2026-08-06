class MyCircularDeque {

    int[] deque;
    int front;
    int rear;
    int size;
    int capacity;

    public MyCircularDeque(int k) {
        deque = new int[k];
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
    }

    public boolean insertFront(int value) {

        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;

        if (size == 1)
            rear = front;

        return true;
    }

    public boolean insertLast(int value) {

        if (isFull())
            return false;

        rear = (rear + 1) % capacity;
        deque[rear] = value;
        size++;

        if (size == 1)
            front = rear;

        return true;
    }

    public boolean deleteFront() {

        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    public boolean deleteLast() {

        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;

        return true;
    }

    public int getFront() {
        if (isEmpty())
            return -1;
        return deque[front];
    }

    public int getRear() {
        if (isEmpty())
            return -1;
        return deque[rear];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}