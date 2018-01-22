part of swagger.api;

@Entity()
class ModelBreak {
  /* earliest start of break */
  @Property(name: 'earliest')
  int earliest = null;
  
/* latest start of break */
  @Property(name: 'latest')
  int latest = null;
  
/* duration of break */
  @Property(name: 'duration')
  int duration = null;
  
/* max driving time without break */
  @Property(name: 'max_driving_time')
  int maxDrivingTime = null;
  
/* initial driving time, i.e. the time your driver has already spent for driving */
  @Property(name: 'initial_driving_time')
  int initialDrivingTime = null;
  
/* array of splits */
  @Property(name: 'possible_split')
  List<int> possibleSplit = [];
  
  ModelBreak();

  @override
  String toString()  {
    return 'ModelBreak[earliest=$earliest, latest=$latest, duration=$duration, maxDrivingTime=$maxDrivingTime, initialDrivingTime=$initialDrivingTime, possibleSplit=$possibleSplit, ]';
  }
}

