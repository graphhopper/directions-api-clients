part of swagger.api;

@Entity()
class Stop {
  
  @Property(name: 'address')
  Address address = null;
  
/* duration of stop, i.e. time in seconds the corresponding activity takes */
  @Property(name: 'duration')
  int duration = null;
  
/* preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location */
  @Property(name: 'preparation_time')
  int preparationTime = null;
  
/* array of time windows. currently, only a single time window is allowed */
  @Property(name: 'time_windows')
  List<TimeWindow> timeWindows = [];
  
  Stop();

  @override
  String toString()  {
    return 'Stop[address=$address, duration=$duration, preparationTime=$preparationTime, timeWindows=$timeWindows, ]';
  }
}

