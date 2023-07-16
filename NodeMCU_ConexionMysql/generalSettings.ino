bool startingConnection(){
  bool connection = 0;
  WiFi.mode(WIFI_STA); //Modo Workstation
  Serial.print("Conectando a la red: ");
  Serial.println(ssid);
  settingIPFix();
  while (WiFi.status() != WL_CONNECTED){  //Ciclo hasta que esté conectado
    WiFi.begin(ssid, password); //Comienza la conexión con el SSID y password
    Serial.print(".");
    delay(5000);
  }
  Serial.println("Conectado exitosamente");
  connection = 1;
  return connection;
}

void settingIPFix(){
  IPAddress ip(192, 168, 100, 27);  //Dirección IP que quieres que te asignen
  IPAddress gateway(192, 168, 100, 1);  //Puerta de enlace, ver en ipconfig /all
  IPAddress subnet(255, 255, 255, 0); //Máscara de subred, ver en ipconfig /all
  WiFi.config(ip, gateway, subnet); //Crea la configuración con las tres IP anteriores
  Serial.print("IP fija asignada: ");
  Serial.println(WiFi.localIP());
}
