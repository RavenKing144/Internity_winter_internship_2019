import socket

s = socket.socket()

def main():
    
    host = socket.gethostname()
    port = 12345
    s.connect((host, port))


    response  = input('If you want to\nLogin, press 1\nCreate New Account, press 2\nDelete Existing Account, press 3\n: ')
    if(response==1):
        sendLoginInformation()
    elif(response==2):
        createacc()
    #elif(response==3):
        #delacc()
    else:
        print("invalid input")
	
def createacc():   
    username = input("Create a username:")
    password = input("Create a password:")
    s.sendall(username.encode())
    s.sendall(password.encode())
    print(s.recv(1024).decode())
    
    print('Your Account has been created, please login using same username and password')

def sendLoginInformation():
    check = 1
    s.sendall(str(check))
    username = input("Username: ")
    password = input("Password: ")
    s.sendall(username.encode())
    s.sendall(password.encode())
    print(s.recv(1024).decode())
    
    
    print("Would you like to logout?")
    response = input("Yes or No >> ")
    s.sendall(response.encode())
    print(s.recv(1024).decode())
    
        
    s.close()

main()
