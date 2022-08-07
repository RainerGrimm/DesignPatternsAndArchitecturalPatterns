# -*- coding: utf-8 -*-

class Coffeein:
    def instruction(self):
        self.boilWater()
        self.addCaffeine()
        self.infuseWater()
        self.addIngredient()
        self.stir()

    def boilWater(self):
        print("Boil the water")

    def infuseWater(self):
        print("Add water")

    def stir(self):
        print("Stir")

    def addCaffeine(self):
        raise NotImplementedError

    def addIngredient(self):
        raise NotImplementedError


class Coffee(Coffeein):
    def addCaffeine(self):
        print("Add coffee")

    def addIngredient(self):
        print("Add sugar")


class Tee(Coffeein):
    def addCaffeine(self):
        print("Add tee")

    def addIngredient(self):
        print("Add milk")


if __name__ == "__main__":
    coffee = Coffee()
    tee = Tee()

    coffee.instruction()
    tee.instruction()
