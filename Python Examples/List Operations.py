values = []

def getInput():
    n = input("Enter n")
    n = int(n)
    if(n<=0):
        print("Invalid input")
    else:
        for i in range(0,n):
            str_data = input()
            process_data(str_data)

def process_data(data):
    global values
    input_data = data.split()
    if(input_data[0] == 'insert'):
        values.insert(int(input_data[1]), int(input_data[2]))
    elif(input_data[0] == 'print'):
        print(values)
    elif(input_data[0] == 'remove'):
        values.remove(int(input_data[1]))                
    elif(input_data[0] == 'append'):
        values.append(int(input_data[1]))
    elif(input_data[0] == 'sort'):
        values.sort()
    elif(input_data[0] == 'pop'):
        values.pop(len(values)-1)
    elif(input_data[0] == 'reverse'):
        values.reverse()


def main():
    getInput()

    
if __name__== "__main__":
    main()
