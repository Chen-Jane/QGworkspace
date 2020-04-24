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
		//监听指定的端口
		int port = 46666;
		ServerSocket server = new ServerSocket(port);
		
		//server将一直等待连接的到来
		System.out.println("server将一直等待连接的到来");
		Socket socket = null;
		while(true) {
			//检查是否有连接，若没有则停止
			socket = server.accept();
			if(socket.isConnected()) {
				System.out.println(socket.getInetAddress().getHostAddress()
								+" is connected ! ");  //获取已连接的客户端的IP
				//开启新线程接收文件，主线程继续回去while检查有无连接
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
			System.out.println("发送结束！");
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

