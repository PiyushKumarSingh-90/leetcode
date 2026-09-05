class Solution:
    def scoreValidator(self, events):
        score = 0
        counter = 0

        for event in events:

            if counter == 10:
                break

            if event.isdigit():
                score += int(event)

            elif event == "W":
                counter += 1

            elif event == "WD" or event == "NB":
                score += 1

        return [score, counter]