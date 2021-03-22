package com.kh.arduino.model.vo;

import java.sql.Timestamp;

public class Dht {

	private long no;
	private String place;
	private double humidity;
	private double celcius;
	private double heatIndex;
	private Timestamp time;
	public Dht() {
		super();
		// TODO Auto-generated constructor stub
	}
	public Dht(long no, String place, double humidity, double celcius, double heatIndex, Timestamp time) {
		super();
		this.no = no;
		this.place = place;
		this.humidity = humidity;
		this.celcius = celcius;
		this.heatIndex = heatIndex;
		this.time = time;
	}
	public long getNo() {
		return no;
	}
	public void setNo(long no) {
		this.no = no;
	}
	public String getPlace() {
		return place;
	}
	public void setPlace(String place) {
		this.place = place;
	}
	public double getHumidity() {
		return humidity;
	}
	public void setHumidity(double humidity) {
		this.humidity = humidity;
	}
	public double getCelcius() {
		return celcius;
	}
	public void setCelcius(double celcius) {
		this.celcius = celcius;
	}
	public double getHeatIndex() {
		return heatIndex;
	}
	public void setHeatIndex(double heatIndex) {
		this.heatIndex = heatIndex;
	}
	public Timestamp getTime() {
		return time;
	}
	public void setTime(Timestamp time) {
		this.time = time;
	}
	@Override
	public String toString() {
		return "Dht [no=" + no + ", place=" + place + ", humidity=" + humidity + ", celcius=" + celcius + ", heatIndex="
				+ heatIndex + ", time=" + time + "]";
	}
	
	
}