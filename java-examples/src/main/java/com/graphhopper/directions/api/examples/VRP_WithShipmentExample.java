package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.api.VrpApi;
import com.graphhopper.directions.api.client.api.SolutionApi;
import com.graphhopper.directions.api.client.model.*;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by schroeder on 21/05/15.
 */
public class VRP_WithShipmentExample {

    public static void main(String[] args) throws Exception {
        new VRP_WithShipmentExample().start();
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

        Vehicle vehicle1 = new Vehicle();
        vehicle1.setVehicleId("vehicle1");
        vehicle1.setStartAddress(createAddress("gera", 50.877044, 12.076721));
        vehicle1.setTypeId("vehicle_type_1");
        vehicle1.setSkills(Arrays.asList("loading bridge"));
        vehicle1.setLatestEnd(50000L);
        vehicles.add(vehicle1);

        Vehicle vehicle2 = new Vehicle();
        vehicle2.setVehicleId("vehicle2");
        vehicle2.setStartAddress(createAddress("erfurt", 50.977723, 11.028771));
        vehicle2.setTypeId("vehicle_type_1");
//        vehicle2.setEarliestStart( 0L );
//        vehicle2.setLatestEnd(20000L);
        vehicles.add(vehicle2);

        request.setVehicles(vehicles);

        /*
        specify vehicle type
         */
        List<VehicleType> types = new ArrayList<VehicleType>();
        VehicleType type = new VehicleType();
        type.setProfile(VehicleType.ProfileEnum.CAR);
        type.setTypeId("vehicle_type_1");
        //with three capacity dimensions
        type.setCapacity(Arrays.asList(5));
        types.add(type);

        request.setVehicleTypes(types);

        /*
        specify your services
         */
        List<Shipment> shipments = new ArrayList<Shipment>();

        Shipment shipment1 = new Shipment();
        shipment1.setId("shipment1");
        shipment1.setName("pick-in-berlin-deliver-in-rostock");
        shipment1.setPickup(createStop("berlin", 52.514549, 13.354568));
        shipment1.setDelivery(createStop("rostock", 54.0833333, 12.1333333));
        shipment1.setSize(Arrays.asList(2));

        Shipment shipment2 = new Shipment();
        shipment2.setId("shipment2");
        shipment2.setName("pick-in-berlin-deliver-in-bremen");
        shipment2.setPickup(createStop("berlin", 52.514549, 13.354568));
        shipment2.setDelivery(createStop("bremen", 53.041213, 8.822021));
        shipment2.setSize(Arrays.asList(1));

        Shipment shipment3 = new Shipment();
        shipment3.setId("shipment3");
        shipment3.setName("pick-in-ulm-deliver-in-dresden");
        shipment3.setPickup(createStop("ulm", 48.398209, 9.990692));
        shipment3.setDelivery(createStop("dresden", 51.050028, 13.738403));
        shipment3.setSize(Arrays.asList(1));
        shipment3.setRequiredSkills(Arrays.asList("loading bridge"));

        shipments.add(shipment1);
        shipments.add(shipment2);
        shipments.add(shipment3);

        request.setShipments(shipments);

        return request;
    }

    private Stop createStop(String id, double lat, double lon) {
        Stop stop = new Stop();
        stop.setAddress(createAddress(id, lat, lon));
        stop.setDuration(2000L);
//        stop.setTimeWindows(Arrays.asList( createTimeWindow( 0L, 15000L) ));
        return stop;
    }

    public Address createAddress(String locationId, double lat, double lon) {
        Address a = new Address();
        a.setLat(lat);
        a.setLon(lon);
        a.setLocationId(locationId);
        return a;
    }

    private TimeWindow createTimeWindow(long earliest, long latest) {
        TimeWindow timeWindow = new TimeWindow();
        timeWindow.setEarliest(earliest);
        timeWindow.setLatest(latest);
        return timeWindow;
    }

}
