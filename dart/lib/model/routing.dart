part of swagger.api;

@Entity()
class Routing {
  /* indicates whether solution should come with route geometries */
  @Property(name: 'calc_points')
  bool calcPoints = null;
  
/* indicates whether historical traffic information should be considered */
  @Property(name: 'consider_traffic')
  bool considerTraffic = null;
  
/* specifies the data provider */
  @Property(name: 'network_data_provider')
  String networkDataProvider = null;
  //enum networkDataProviderEnum {  openstreetmap,  tomtom,  };
/* indicates whether matrix calculation should fail fast when points cannot be connected */
  @Property(name: 'fail_fast')
  bool failFast = null;
  
  Routing();

  @override
  String toString()  {
    return 'Routing[calcPoints=$calcPoints, considerTraffic=$considerTraffic, networkDataProvider=$networkDataProvider, failFast=$failFast, ]';
  }
}

