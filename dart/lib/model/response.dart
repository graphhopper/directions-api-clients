part of swagger.api;

@Entity()
class Response {
  
  @Property(name: 'copyrights')
  List<String> copyrights = [];
  
/* unique identify of job - which you get when posting your request to the large problem solver */
  @Property(name: 'job_id')
  String jobId = null;
  
/* indicates the current status of the job */
  @Property(name: 'status')
  String status = null;
  //enum statusEnum {  waiting_in_queue,  processing,  finished,  };
/* waiting time in ms */
  @Property(name: 'waiting_time_in_queue')
  int waitingTimeInQueue = null;
  
/* processing time in ms. if job is still waiting in queue, processing_time is 0 */
  @Property(name: 'processing_time')
  int processingTime = null;
  
/* the solution. only available if status field indicates finished */
  @Property(name: 'solution')
  Solution solution = null;
  
  Response();

  @override
  String toString()  {
    return 'Response[copyrights=$copyrights, jobId=$jobId, status=$status, waitingTimeInQueue=$waitingTimeInQueue, processingTime=$processingTime, solution=$solution, ]';
  }
}

