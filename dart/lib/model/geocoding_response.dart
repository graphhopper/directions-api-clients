part of swagger.api;

@Entity()
class GeocodingResponse {
  
  @Property(name: 'hits')
  List<GeocodingLocation> hits = [];
  

  @Property(name: 'locale')
  String locale = null;
  
  GeocodingResponse();

  @override
  String toString()  {
    return 'GeocodingResponse[hits=$hits, locale=$locale, ]';
  }
}

