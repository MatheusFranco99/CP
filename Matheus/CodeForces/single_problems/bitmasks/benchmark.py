
import random
import subprocess


def get_1847B():

    n = 2
    size = [10, 10, 10, 100, 100, 100, 1000, 1000, 1000, 1000000]
    max_elm_value = [10,100,1000, 10, 100, 1000, 10, 100, 1000, 1000000]

    tests = []
    for i, size_i in enumerate(size):

        test_i = {'description':f"Size {size_i}, max value {max_elm_value[i]}"}

        def test_call(i=i):
            # with open("temp.txt","w") as f:

            lines = ""
            lines += f"{n}\n"
            for _ in range(n):
                lines += f"{size[i]}\n"
                values = [str(random.randint(1,max_elm_value[i]+1)) for _ in range(size[i])]
                value_str = " ".join(values)
                lines += f"{value_str}\n"


            results = subprocess.check_output(['python3', '1847B.py'],input=lines.encode("utf-8")).decode("utf-8")

            return results.split("\n")

        test_i['call'] = lambda i=i: test_call(i)

        tests += [test_i]

    return tests


def get_tests() -> list:

    return get_1847B()

if __name__ == "__main__":


    tests = get_tests()

    for test in tests:
        print("="*30)
        print(test['description'])
        result = test['call']()
        print("->",result)
        for line in result:
            if "mean: " in line:
                print(line)
            if "stdev: " in line:
                print(line)