class StrategyExample:
    def __init__(self , func = None):
        if func: self.execute = func
    def execute(self): 
        print("Original")

def replacement1():
    print("Strategy 1")

def replacement2():
    print("Strategy 2")

if __name__ == "__main__":
    strat0 = StrategyExample()
    strat1 = StrategyExample(replacement1)
    strat2 = StrategyExample(replacement2)

    strat0.execute()
    strat1.execute()
    strat2.execute()