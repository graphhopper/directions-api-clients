part of swagger.api;

@Entity()
class Location {
  /* longitude */
  @Property(name: 'lon')
  double lon = null;
  
/* latitude */
  @Property(name: 'lat')
  double lat = null;
  
  Location();

  @override
  String toString()  {
    return 'Location[lon=$lon, lat=$lat, ]';
  }
}

