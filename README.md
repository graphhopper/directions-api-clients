# graphhopper-routing-api-swagger
Swagger definition for the GraphHopper Routing Api

## Getting Started

Install Swagger Codegen, for example:
```
wget https://oss.sonatype.org/content/repositories/releases/io/swagger/swagger-codegen-cli/2.2.1/swagger-codegen-cli-2.2.1.jar
```

Sample Run Routing CodeGen for Java:
```
java -jar swagger-codegen-cli-2.2.1.jar  generate -i routing_swagger.yaml -l java -o ../graphhopper-routing-api-generated/java
```

Sample Run Isochrone CodeGen for Java:
```
java -jar swagger-codegen-cli-2.2.1.jar  generate -i isochrone_swagger.yaml -l java -o ../graphhopper-isochrone-api-generated/java
```