class Observable:
    def __init__(self):
        self.__observers = []

    def register_observer(self, observer):
        self.__observers.append(observer)

    def notify_observers(self):
        for observer in self.__observers:
            observer.notify(self)


class Observer:
    def __init__(self, observable):
        observable.register_observer(self)

    def notify(self, observable):
        print("notified from " + observable.__class__.__name__)


subject = Observable()
observer = Observer(subject)
subject.notify_observers()
