package Socket;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {
	public static void main(String[] args) throws IOException {
		//����ָ���Ķ˿�
		int port = 46666;
		ServerSocket server = new ServerSocket(port);
		
		//server��һֱ�ȴ����ӵĵ���
		System.out.println("server��һֱ�ȴ����ӵĵ���");
		Socket socket = null;
		while(true) {
			//����Ƿ������ӣ���û����ֹͣ
			socket = server.accept();
			if(socket.isConnected()) {
				System.out.println(socket.getInetAddress().getHostAddress()
								+" is connected ! ");  //��ȡ�����ӵĿͻ��˵�IP
				//�������߳̽����ļ������̼߳�����ȥwhile�����������
				new Thread(new Upload(socket)).start();
			}
		}
	}	
}
class Upload implements Runnable{
	Socket socket = null;
	BufferedInputStream inputStream = null;
	BufferedOutputStream outputStream = null;
	InputStream is = null;
	
	public Upload(Socket socket) {
		this.socket = socket;
	}
	public void run() {
		try {
			is = socket.getInputStream();
			byte[] bytes = new byte[1024];
			int len = 0;
			StringBuilder filePath = new StringBuilder();
			while((len = is.read(bytes)) != -1) {
				filePath.append(new String(bytes,0,len,"UTF-8"));
			}
			inputStream = new BufferedInputStream(new FileInputStream(new File(""+filePath)));
			outputStream = new BufferedOutputStream(socket.getOutputStream());
			byte[] bytes1 = new byte[1024];
			int len1 = 0;
			while((len1 = inputStream.read(bytes1)) != -1) {
				outputStream.write(bytes1, 0, len);
				outputStream.flush();
			}
			socket.shutdownOutput();
			System.out.println("���ͽ�����");
		} catch (IOException e) {
			e.printStackTrace();
		}finally{
			try {
				is.close();
				socket.close();
				inputStream.close();
				outputStream.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
}

