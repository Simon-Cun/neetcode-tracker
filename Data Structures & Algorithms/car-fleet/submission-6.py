class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        distance = []

        for i in range(len(position)):
            distance.append((target - position[i]) / speed[i])
        zipped = list(zip(position, distance))
        sorted_zip = sorted(zipped, reverse=True)

        _, unzip = list(zip(*sorted_zip))
        fleets = 0
        prev = 0
        for y in unzip:
            if prev < y:
                fleets += 1
                prev = y
            
        return fleets