from socket import *
serverName = '192.168.123.20'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
sentence = input('Input the lower case sentence')
clientSocket.send(bytes(sentence,'utf-8'))
modifiedSentence = clientSocket.recv(1024)
print(modifiedSentence.decode('utf-8'))
clientSocket.close()

