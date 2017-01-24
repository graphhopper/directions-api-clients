#import "SWGResponse.h"

@implementation SWGResponse

- (instancetype)init {
  self = [super init];
  if (self) {
    // initialize property's default value, if any
    
  }
  return self;
}


/**
 * Maps json key to property name.
 * This method is used by `JSONModel`.
 */
+ (JSONKeyMapper *)keyMapper {
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"varCopyrights": @"copyrights", @"jobId": @"job_id", @"status": @"status", @"waitingInQueue": @"waiting_in_queue", @"processingTime": @"processing_time", @"solution": @"solution" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"varCopyrights", @"jobId", @"status", @"waitingInQueue", @"processingTime", @"solution"];
  return [optionalProperties containsObject:propertyName];
}

@end
