part of swagger.api;

@Entity()
class IsochroneResponsePolygonProperties {
  
  @Property(name: 'bucket')
  int bucket = null;
  
  IsochroneResponsePolygonProperties();

  @override
  String toString()  {
    return 'IsochroneResponsePolygonProperties[bucket=$bucket, ]';
  }
}

