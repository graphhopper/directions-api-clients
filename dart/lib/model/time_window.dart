part of swagger.api;

@Entity()
class TimeWindow {
  /* earliest start time of corresponding activity */
  @Property(name: 'earliest')
  int earliest = null;
  
/* latest start time of corresponding activity */
  @Property(name: 'latest')
  int latest = null;
  
  TimeWindow();

  @override
  String toString()  {
    return 'TimeWindow[earliest=$earliest, latest=$latest, ]';
  }
}

