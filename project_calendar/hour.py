class Hour:
    def __init__(self, name):
        """
        :param name: number of hour
        str: string with plan of hour
        """
        self.name = name
        self.str = ""

    def change_string(self, new_string):
        """
        :param new_string: new text to change
        :return: None
        """
        self.str = new_string

    def get_hour_plan(self):
        """
        :return: string hour + plan
        """
        # hour_plan = f"{self.name}:00 | {self.str}"

        if self.name < 10:
            hour = f"0{self.name}:00"
        else:
            hour = f"{self.name}:00"
        hour_plan = [hour, self.str]
        return hour_plan
