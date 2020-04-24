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
		
		//Ҫ���ӵķ����IP��ַ�Ͷ˿�
		String host = "192.168.155.1";
		int port = 46666;
		//�����˽�������
		Socket socket = new Socket(host,port);
		//�������Ӻ��������
		BufferedOutputStream os =  new BufferedOutputStream(socket.getOutputStream());
		BufferedInputStream inputStream = null;
		BufferedOutputStream outputStream = null;
		PrintWriter return_txt = null;
		Scanner scanner = new Scanner(System.in);
		System.out.println("������Ҫ���ص��ļ�·�����磺C:/Users/Documents/demo.txt)��");
		String filePath = scanner.nextLine();
		socket.getOutputStream().write(filePath.getBytes("UTF-8"));
		//������ȡ�ļ���
		Scanner scanner2 = new Scanner(System.in);
		System.out.println("����ļ�������");
		String fileName = scanner2.nextLine();
		//��socket�л�ȡ�������ʹ����ļ�
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
			return_txt.println("�ͻ��˽��ճɹ���");
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
