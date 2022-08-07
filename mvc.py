class DefectModel:
    def __init__(self):
        self.__defects={"XYZ": "File doesn't get deleted.",
                        "XAB": "Registry doesn't get created.",
                        "ABC": "Wrong title get displayed."}

    def getDefectComponent(self, component):
        return self.__defects[component]

    def getSummary(self):
        return len(self.__defects)

    def getList(self):
        return list(self.__defects.items())

class DefectView:
    def getSummary(self, num):
        return "Their are " + str(num) + " defects in total!"

    def getDefectComponent(self, defect):
        return "Defect of component:" + defect

    def getList(self, defects):
        out= ""
        for (key, value) in defects:
            out += "(" + key + ", " + value + ")\n"
        return out

class DefectController:
    def __init__(self):
        self.__model= DefectModel()
        self.__view= DefectView()

    def getDefectComponent(self, component):
        return self.__view.getDefectComponent(self.__model.getDefectComponent(component))

    def getDefectSummary(self):
        return self.__view.getSummary(self.__model.getSummary())

    def getDefectList(self):
        return self.__view.getList(self.__model.getList())

controller = DefectController()

print(controller.getDefectComponent("ABC"))
print()
print(controller.getDefectSummary())
print()
print(controller.getDefectList())






