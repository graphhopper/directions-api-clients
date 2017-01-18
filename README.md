# graphhopper-routing-api-swagger
Swagger definition for the GraphHopper Routing Api

## Getting Started

Install Swagger Codegen, for example:
```
wget https://oss.sonatype.org/content/repositories/releases/io/swagger/swagger-codegen-cli/2.2.1/swagger-codegen-cli-2.2.1.jar
```

Sample Run CodeGen for Java:
```
java -jar swagger-codegen-cli-2.2.1.jar  generate -i swagger.yaml -l java -o ../graphhopper-direction-api-generated/java -c swagger-config.json
```