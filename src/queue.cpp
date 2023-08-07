#include "queue.h"

namespace my {
  Queue::Queue(int t_capacity)
      : m_capacity(t_capacity), mp_array(new int[t_capacity]) {}

  Queue::~Queue() { delete[] mp_array; }

  int Queue::count() { return m_count; }

  int Queue::capacity() { return m_capacity; }

  /**
   * @brief
   * TODO: throw exception when queue is full.
   * @param item
   */
  void Queue::enqueue(int item) {
    if (m_count >= m_capacity) {
      throw 10;
      // throw "Queue Full!";
    }

    m_rear++;
    m_rear = m_rear % m_capacity;
    mp_array[m_rear] = item;
    m_count++;
  }

  /**
   * @brief
   * TODO: throw exception when queue is empty.
   * @return int
   */
  int Queue::dequeue() {
    if (m_count == 0) {
      throw 20;
      // throw "Queue Empty!";
    }

    auto result = mp_array[m_front];
    m_front++;
    m_front = m_front % m_capacity;
    m_count--;

    return result;
  }

  bool Queue::isFull() {
    if (m_count == m_capacity) {
      return true;
    } else {
      return false;
    }
  }
  bool Queue::isEmpty() {
    if (m_count == 0) {
      return true;
    } else {
      return false;
    }
  }
} // namespace my