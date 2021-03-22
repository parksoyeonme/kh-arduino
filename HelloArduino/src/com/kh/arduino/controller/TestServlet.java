package com.kh.arduino.controller;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class TestServlet
 */
@WebServlet("/test")
public class TestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//0. encoding처리
		request.setCharacterEncoding("utf-8");
		
		//1. 사용자 입력값 처리
		String name = request.getParameter("name");
		int num = Integer.parseInt(request.getParameter("num"));
		System.out.println(request.getMethod());
		System.out.println("name = " + name);
		System.out.println("num = " + num);
		
		//2. 업무로직
		
		//3. 응답처리
		response.getWriter().print(1);
		
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}