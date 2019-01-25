#include <iostream>

#define Max 10
class QueueClass{

private:
  int items[Max];
  int front;
  int rear;
  int count;

public:
  QueueClass(): front(-1), rear(-1), count(0) {}

  int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    else{
      return 0;
    }
  }

  int isFull(){
    if(rear == Max -1){
      return 1;
    }
    else{
      return 0;
    }
  }

void enqueue(){
  int item;
  std::cout << "Enter the item: ";
  std::cin >> item;
  if(isFull()){
    std::cout << "Queue is full :(" << std::endl;
  }
  else{
    if(front == -1){
      front++;
    }
    rear++;
    items[rear] = item;
    count++;
  }
}

void dequeue(){
  if(isEmpty()){
    std::cout << "Queue is empty :(" << std::endl;
  }
  else{
    std::cout << "Item dequeued: " << items[front];
    front++;
    count--;
  }
}

void display(){
  if(isEmpty()){
    std::cout << "Queue is empty :(";
  }
  else{
    std::cout << std::endl;
    std::cout << "---Result---" << std::endl;
    for(int i = rear; i >= front; i--){
      std::cout << items[i];
      if(i != front){
        std::cout << "-->";
      }
    }
    std::cout << std::endl;
  }
}

void getCount(){
  std::cout << "Total count: " << count << std::endl;
}

void peak(){
  std::cout << "Peak value: " << items[rear] << std::endl;
}

};

int main(){
  QueueClass qc;
  int loop = 1;
  int ch;
  do {

    std::cout << std::endl;
    std::cout << "1. Enqueue" << std::endl;
    std::cout << "2. Dequeue" << std::endl;
    std::cout << "3. Peak" << std::endl;
    std::cout << "4. Display" << std::endl;
    std::cout << "5. Count" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> ch;

    switch (ch) {
      case 1: qc.enqueue();
              break;
      case 2: qc.dequeue();
              break;
      case 3: qc.peak();
              break;
      case 4: qc.display();
              break;
      case 5: qc.getCount();
              break;
      case 6: std::cout << "Thank you.. !!!" << std::endl;
              loop = 0;
              exit(0);
              break;
      case 7: std::cout << "Invalid choice" << std::endl;
              break;
    }

  } while(loop);
  return 1;
}
