part of swagger.api;

@Entity()
class ResponseCoordinates {
  
  @Property(name: 'coordinates')
  ResponseCoordinatesArray coordinates = null;
  
  ResponseCoordinates();

  @override
  String toString()  {
    return 'ResponseCoordinates[coordinates=$coordinates, ]';
  }
}

