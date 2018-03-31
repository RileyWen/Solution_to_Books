from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print('Tcp Server Ready')
while True:
	connectionSocket, addr = serverSocket.accept()
	print('Tcp connection from'+str(addr))
	sentence=connectionSocket.recv(1024)
	upperSentence = sentence.decode('utf-8').upper()
	connectionSocket.send(bytes(upperSentence,'utf-8'))
	connectionSocket.close()