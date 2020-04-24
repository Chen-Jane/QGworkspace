package Socket;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import org.omg.CORBA.portable.OutputStream;

public class Client {
	
public static void main(String[] args) throws UnknownHostException, IOException {
		
		//要连接的服务端IP地址和端口
		String host = "192.168.155.1";
		int port = 46666;
		//与服务端建立连接
		Socket socket = new Socket(host,port);
		//建立连接后获得输出流
		BufferedOutputStream os =  new BufferedOutputStream(socket.getOutputStream());
		BufferedInputStream inputStream = null;
		BufferedOutputStream outputStream = null;
		PrintWriter return_txt = null;
		Scanner scanner = new Scanner(System.in);
		System.out.println("输入想要下载的文件路径（如：C:/Users/Documents/demo.txt)：");
		String filePath = scanner.nextLine();
		socket.getOutputStream().write(filePath.getBytes("UTF-8"));
		//从外界获取文件名
		Scanner scanner2 = new Scanner(System.in);
		System.out.println("请给文件命名：");
		String fileName = scanner2.nextLine();
		//从socket中获取输入流和创建文件
		try {
			inputStream = new BufferedInputStream(socket.getInputStream());
			outputStream = new BufferedOutputStream(new FileOutputStream(fileName));
			return_txt = new PrintWriter(new OutputStreamWriter
												(socket.getOutputStream()),true);
			byte[] bytes = new byte[1024];
			int len = 0;
			while((len = inputStream.read(bytes))!=-1) {
				outputStream.write(bytes, 0, len);
				outputStream.flush();
			}
			return_txt.println("客户端接收成功！");
		} catch (IOException e) {		
			e.printStackTrace();
		}finally {
			try {
				os.close();
				socket.close();
				return_txt.close();
				inputStream.close();
				outputStream.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

}
