#ifndef MY_QUEUE_H
#define MY_QUEUE_H

namespace my {
  class Queue {
  private:
    int m_front = 0;
    int m_rear = -1;
    int *mp_array;
    int m_capacity;
    int m_count = 0;

  public:
    Queue(int);
    ~Queue();

    void enqueue(int);
    int dequeue();
    int count();
    int capacity();
    bool isFull();
    bool isEmpty();
  };

} // namespace my
#endif