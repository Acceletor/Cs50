class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Wrong capacity")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return self.size * '🍪'

    def deposit(self, n):
        if n + self.size > 12:
            raise ValueError("Jar is full")
        else:
            self._size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError("Aren't that many cookies in cookies jar")
        else:
            self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

def main():
    jar = Jar()
    jar.deposit(9)
    print(jar)
    jar.withdraw(2)
    print(jar)

main()