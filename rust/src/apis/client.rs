use std::rc::Rc;

use hyper;
use super::configuration::Configuration;

pub struct APIClient<C: hyper::client::Connect> {
  configuration: Rc<Configuration<C>>,
  geocoding_api: Box<::apis::GeocodingApi>,
  isochrone_api: Box<::apis::IsochroneApi>,
  matrix_api: Box<::apis::MatrixApi>,
  routing_api: Box<::apis::RoutingApi>,
  solution_api: Box<::apis::SolutionApi>,
  vrp_api: Box<::apis::VrpApi>,
}

impl<C: hyper::client::Connect> APIClient<C> {
  pub fn new(configuration: Configuration<C>) -> APIClient<C> {
    let rc = Rc::new(configuration);

    APIClient {
      configuration: rc.clone(),
      geocoding_api: Box::new(::apis::GeocodingApiClient::new(rc.clone())),
      isochrone_api: Box::new(::apis::IsochroneApiClient::new(rc.clone())),
      matrix_api: Box::new(::apis::MatrixApiClient::new(rc.clone())),
      routing_api: Box::new(::apis::RoutingApiClient::new(rc.clone())),
      solution_api: Box::new(::apis::SolutionApiClient::new(rc.clone())),
      vrp_api: Box::new(::apis::VrpApiClient::new(rc.clone())),
    }
  }

  pub fn geocoding_api(&self) -> &::apis::GeocodingApi{
    self.geocoding_api.as_ref()
  }

  pub fn isochrone_api(&self) -> &::apis::IsochroneApi{
    self.isochrone_api.as_ref()
  }

  pub fn matrix_api(&self) -> &::apis::MatrixApi{
    self.matrix_api.as_ref()
  }

  pub fn routing_api(&self) -> &::apis::RoutingApi{
    self.routing_api.as_ref()
  }

  pub fn solution_api(&self) -> &::apis::SolutionApi{
    self.solution_api.as_ref()
  }

  pub fn vrp_api(&self) -> &::apis::VrpApi{
    self.vrp_api.as_ref()
  }


}
