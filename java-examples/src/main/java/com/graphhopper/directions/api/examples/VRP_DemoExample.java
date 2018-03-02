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
public class VRP_DemoExample {

    public static void main(String[] args) throws Exception {
        new VRP_DemoExample().start();
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
//            System.out.println(rsp);
//            if(rsp.getStatus() == null) continue;
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
        vehicles.add(vehicle1);

        Vehicle vehicle2 = new Vehicle();
        vehicle2.setVehicleId("vehicle2");
        vehicle2.setStartAddress(createAddress("erfurt", 50.977723, 11.028771));
        vehicle2.setTypeId("vehicle_type_1");
        vehicles.add(vehicle2);

        request.setVehicles(vehicles);

        /*
         specify vehicle type
         */
        List<VehicleType> types = new ArrayList<VehicleType>();
        VehicleType type = new VehicleType();
        type.setProfile(VehicleType.ProfileEnum.CAR);
        type.setTypeId("vehicle_type_1");
        type.setCapacity(Arrays.asList(5));
        types.add(type);

        request.setVehicleTypes(types);

        /*
         specify your services
         */
        List<Service> services = new ArrayList<Service>();

        Service rostock = createService("rostock", 54.0833333, 12.1333333);
        rostock.setName("drink_bionade_in_rostock");
        rostock.setSize(Arrays.asList(1));
        services.add(rostock);

        Service berlin = createService("berlin", 52.514549, 13.354568);
        berlin.setName("drink_cola_in_berlin");
        berlin.setSize(Arrays.asList(1));
        services.add(berlin);

        Service ulm = createService("ulm", 48.398209, 9.990692);
        ulm.setName("drink_juice_in_ulm");
        ulm.setSize(Arrays.asList(1));
        services.add(ulm);

        Service dresden = createService("dresden", 51.050028, 13.738403);
        dresden.setName("drink_nothing_in_dresden");
        dresden.setSize(Arrays.asList(1));
        services.add(dresden);

        Service kassel = createService("kassel", 51.31173, 9.486694);
        kassel.setName("drink_wine_in_kassel");
        kassel.setSize(Arrays.asList(1));
        services.add(kassel);

        Service dortmund = createService("dortmund", 51.508742, 7.500916);
        dortmund.setName("drink_beer_in_dortmund");
        dortmund.setSize(Arrays.asList(1));
        services.add(dortmund);

        Service karlsruhe = createService("karlsruhe", 49.0047222, 8.3858333);
        karlsruhe.setName("drink_vogelbeer_in_karlsruhe");
        karlsruhe.setSize(Arrays.asList(1));
        services.add(karlsruhe);

        Service bremen = createService("bremen", 53.041213, 8.822021);
        bremen.setName("eat_fish_in_bremen");
        bremen.setSize(Arrays.asList(1));
        services.add(bremen);

        Service hof = createService("hof", 50.310392, 11.8927);
        hof.setName("drink_somethingelse_in_hof");
        hof.setSize(Arrays.asList(1));
        services.add(hof);

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
