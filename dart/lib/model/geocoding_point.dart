part of swagger.api;

@Entity()
class GeocodingPoint {
  /* Latitude */
  @Property(name: 'lat')
  double lat = null;
  
/* Longitude */
  @Property(name: 'lng')
  double lng = null;
  
  GeocodingPoint();

  @override
  String toString()  {
    return 'GeocodingPoint[lat=$lat, lng=$lng, ]';
  }
}

