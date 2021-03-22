package com.kh.arduino.controller;

import java.io.IOException;
import java.sql.Timestamp;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.kh.arduino.model.vo.Dht;

/**
 * Servlet implementation class CreateDHTServlet
 */
@WebServlet("/dht/createDht")
public class CreateDHTServlet extends HttpServlet {
   private static final long serialVersionUID = 1L;
   
   protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
      //1. encoding
      
      //2. 사용자 입력값
      String place = request.getParameter("place");
      double humidity = Double.parseDouble(request.getParameter("h"));
      double celcius = Double.parseDouble(request.getParameter("c"));      
      double heatIndex = Double.parseDouble(request.getParameter("hi"));      
      Timestamp time = new Timestamp(System.currentTimeMillis());
      
      Dht dht = new Dht(0, place, humidity, celcius, heatIndex, time);
      System.out.println("dht = " + dht);
      
      
      //3. db에 insert 처리
      
      //4. 응답
      response.getWriter().append("OK");
      
   }

}