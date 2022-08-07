class Singleton:
    _instance = None
    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(Singleton, cls).__new__(cls, *args, **kwargs)
        return cls._instance

class Derived(Singleton): pass

sing1 = Singleton()
sing2 = Derived()

print(sing1)
print(sing2)