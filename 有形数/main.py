import unittest


class Palindrome:
    def __init__(self):
        self.name = 'Palindrome'

    # 获取第 n 个回文数，这里还没有实现
    def get_by_index(self, index):
        return index


class PowerNumber:
    def __init__(self, power_num):
        self.name = 'PowerNumber'
        self.power_num = power_num

    def get_by_index(self, index):
        return index ** self.power_num


class GeneralizedPyramidalNumber:
    def __init__(self, dim_num, edge_num):
        self.name = 'GeneralizedPyramidalNumber'
        self.dim_num = dim_num
        self.edge_num = edge_num

    def get_by_index(self, index):
        ans = 1
        for i in range(self.dim_num-1):
            ans = ans * (index + i) // (i + 1)
        ans = ans*((self.edge_num-2)*index -
                   (self.edge_num-self.dim_num-2))//self.dim_num
        return ans


class StarNumber:
    def __init__(self, angle_num):
        self.name = 'StarNumber'
        self.angle_num = angle_num

    def get_by_index(self, index):
        return index * index * self.angle_num - index * self.angle_num + 1


class PolyhedronNumber:
    def __init__(self, face_num):
        self.name = 'PolyhedronNumber'
        self.face_num = face_num

    def get_by_index(self, index):
        if self.face_num == 4:
            return index * (index+1)*(index+2)//6
        elif self.face_num == 6:
            return index ** 3
        elif self.face_num == 8:
            return index * (2*index**2+1)//3
        elif self.face_num == 12:
            return index * (3*index-1)*(3*index-2)//2
        elif self.face_num == 20:
            return index * (5*index**2-5*index+2)//2
        else:
            return 0


class RhombicDodecahedralNumber:
    def __init__(self):
        self.name = 'RhombicDodecahedralNumber'

    def get_by_index(self, index):
        return 4*index**3-6*index**2+4*index-1


def get_additive_number_count(number, max_num):
    dp = [float('inf')] * (max_num + 1)
    dp[0] = 0
    for i in range(1, max_num + 1):
        min_n = float('inf')
        j = 1
        while number.get_by_index(j) <= i:
            min_n = min(min_n, dp[i - number.get_by_index(j)])
            j += 1
        dp[i] = min_n + 1
    val = 1
    for i in range(1, max_num + 1):
        if dp[i] >= val:
            val = dp[i]
    return val


def print_number(number, max_num):
    for i in range(1, max_num+1):
        print(number.get_by_index(i), end=' ')
    print()


class Test(unittest.TestCase):
    def test_power_number(self):
        self.assertEqual(get_additive_number_count(PowerNumber(2), 1000), 4)
        self.assertEqual(get_additive_number_count(PowerNumber(3), 1000), 9)
        self.assertEqual(get_additive_number_count(PowerNumber(4), 1000), 19)
        self.assertEqual(get_additive_number_count(PowerNumber(5), 1000), 37)
        self.assertEqual(get_additive_number_count(PowerNumber(6), 1000), 73)

    def test_generalized_pyramidal_number(self):
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(2, 3), 1000), 3)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(2, 4), 1000), 4)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(2, 5), 1000), 5)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(3, 3), 1000), 5)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(3, 4), 1000), 6)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(3, 5), 1000), 8)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(3, 6), 1000), 8)
        self.assertEqual(get_additive_number_count(
            GeneralizedPyramidalNumber(3, 7), 1000), 9)

    def test_star_number(self):
        self.assertEqual(get_additive_number_count(StarNumber(5), 1000), 12)
        self.assertEqual(get_additive_number_count(StarNumber(6), 1000), 14)
        self.assertEqual(get_additive_number_count(StarNumber(7), 1000), 16)
        self.assertEqual(get_additive_number_count(StarNumber(8), 1000), 18)
        self.assertEqual(get_additive_number_count(StarNumber(9), 1000), 20)

    def test_polyhedron_number(self):
        self.assertEqual(get_additive_number_count(
            PolyhedronNumber(4), 1000), 5)
        self.assertEqual(get_additive_number_count(
            PolyhedronNumber(6), 1000), 9)
        self.assertEqual(get_additive_number_count(
            PolyhedronNumber(8), 1000), 7)
        self.assertEqual(get_additive_number_count(
            PolyhedronNumber(12), 1000), 22)
        self.assertEqual(get_additive_number_count(
            PolyhedronNumber(20), 1000), 15)

    def test_rhombic_dodecahedral_number(self):
        self.assertEqual(get_additive_number_count(
            RhombicDodecahedralNumber(), 1000), 17)


def main():
    unittest.main()


if __name__ == '__main__':
    main()
