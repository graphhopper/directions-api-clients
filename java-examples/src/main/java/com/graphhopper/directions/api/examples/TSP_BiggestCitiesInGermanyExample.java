package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.api.VrpApi;
import com.graphhopper.directions.api.client.api.SolutionApi;
import com.graphhopper.directions.api.client.model.*;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by schroeder on 21/05/15.
 */
public class TSP_BiggestCitiesInGermanyExample {

    public static void main(String[] args) throws Exception {
        new TSP_BiggestCitiesInGermanyExample().start();
    }

    private void start() throws Exception {

        Request request = createRequest();
        VrpApi vrpApi = new VrpApi();

        // enable debugging for sending and receiving requests
        // ApiClient client = new ApiClient().setDebugging(true);
        // vrpApi.setApiClient(client);        

        String key = System.getProperty("graphhopper.key", "");
        JobId jobId = vrpApi.postVrp(key, request);

        System.out.println(getClass() + ", jobId: " + jobId.getJobId());

        SolutionApi solApi = new SolutionApi();
        Response rsp;

        while (true) {
            rsp = solApi.getSolution(key, jobId.getJobId());
            if (rsp.getStatus().equals(Response.StatusEnum.FINISHED)) {
                break;
            }
            Thread.sleep(200);
        }
        System.out.println(rsp);

    }

    private Request createRequest() {
        Request request = new Request();
        request.setAlgorithm(new Algorithm());

        /*
        specify vehicles
         */
        List<Vehicle> vehicles = new ArrayList<Vehicle>();

        Vehicle v = new Vehicle();
        v.setVehicleId("v1");
        v.setStartAddress(createAddress("berlin", 52.537, 13.406));
        vehicles.add(v);
        request.setVehicles(vehicles);

        /*
        specify your services
         */
        List<Service> services = new ArrayList<Service>();

        services.add(createService("hamburg", 53.552, 9.999));
        services.add(createService("munich", 48.145, 11.570));
        services.add(createService("cologne", 50.936, 6.957));
        services.add(createService("frankfurt", 50.109, 8.670));

        request.setServices(services);

        return request;
    }

    public Address createAddress(String locationId, double lat, double lon) {
        Address a = new Address();
        a.setLat(lat);
        a.setLon(lon);
        a.setLocationId(locationId);
        return a;
    }

    public Service createService(String id, double lat, double lon) {
        Service service = new Service();
        service.setId(id);
        service.setType(Service.TypeEnum.SERVICE);
        service.setAddress(createAddress(id, lat, lon));
        return service;
    }

}
