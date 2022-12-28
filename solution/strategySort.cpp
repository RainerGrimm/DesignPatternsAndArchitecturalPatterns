#include <iostream>

struct AbstractSort {
    virtual void readData() {}
    virtual void sortData() = 0;
    virtual void writeData() {}

    virtual ~AbstractSort() = default;
};

class QuickSort: public AbstractSort{
private:
  void readData() override {
    std::cout << "readData" << '\n';
  }
  void sortData() override {
    std::cout <<  "sortData" << '\n';
  }
  void writeData() override {
    std::cout << "writeData" << '\n';
  }
};

class BubbleSort: public AbstractSort{
private:

  void sortData() override {
    std::cout <<  "sortData" << '\n';
  }

};

class Client {
 public:
    Client(AbstractSort* sort): sortStrategy(sort) {}
    void processData() {
        sortStrategy->readData();
        sortStrategy->sortData();
        sortStrategy->writeData();
    }
    void setStrategy(AbstractSort* sort) {
        sortStrategy = sort;
    }
 private:
     AbstractSort* sortStrategy;
};

int main() {

    std::cout << '\n';

    AbstractSort* sort = new QuickSort;
    Client client(sort);
    client.processData();
    delete sort;

    std::cout << "\n";

    AbstractSort* sort2 = new BubbleSort;
    client.setStrategy(sort2);
    client.processData();
    delete sort2;

    std::cout << '\n';

}

