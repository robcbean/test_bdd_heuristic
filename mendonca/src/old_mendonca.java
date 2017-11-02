import java.io.PrintStream;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import javax.swing.tree.TreeNode;
import splar.core.constraints.PropositionalFormula;
import splar.core.fm.FeatureModel;
import splar.core.fm.FeatureTreeNode;
import splar.core.fm.XMLFeatureModel;
import splar.core.heuristics.FTPreOrderSortedECTraversalHeuristic;
import splar.core.heuristics.VariableOrderingHeuristic;
import splar.core.heuristics.VariableOrderingHeuristicsManager;
import splar.plugins.reasoners.bdd.javabdd.*;
 
 
 
 
public class old_mendonca {
     
    public static void old_main(String[] args) throws Exception {
         
        String fileInput;
        String output;
        //double ecr;
        int bdd_size;
         
        PrintStream tmpOut = System.out;
         
        System.setErr(new NullPrintStream());
        System.setOut(new NullPrintStream());
         
        if( args.length == 0 ) {
            System.err.println("mendoca file.xml");
            return;
        }
        fileInput  = args[0];
         
        FeatureModel featureModel = new XMLFeatureModel(fileInput, XMLFeatureModel.USE_VARIABLE_NAME_AS_ID);
 
        featureModel.loadModel();
     
         
         
        FTPreOrderSortedECTraversalHeuristic traversalHeuristic = new FTPreOrderSortedECTraversalHeuristic("Pre-CL-MinSpan", featureModel, FTPreOrderSortedECTraversalHeuristic.FORCE_SORT);
        //String[] tmp = traversalHeuristic.
         
        VariableOrderingHeuristic heuristic = VariableOrderingHeuristicsManager.createHeuristicsManager().getHeuristic("Pre-CL-MinSpan");
         
        ReasoningWithBDD reasoner = new FMReasoningWithBDD(featureModel, heuristic, 500000, 500000, 600000, "pre-order");
        reasoner.init();
         
     
         
 
 
         
 
         
        String[] order = heuristic.getVariableOrdering();
         
        //double totalfeatures = featureModel.countFeatures() + calcGroupFeatures(featureModel.getRoot())-getFeaturesRemoved(featureModel.getRoot());
        //ecr = (double)(featureModel.countConstraintsVariables()) / totalfeatures * 100.00;
        bdd_size = reasoner.getBDD().nodeCount();
        double symmetric_features = old_mendonca.calcSymmetricFeatures(featureModel.getRoot(),featureModel);
        symmetric_features = symmetric_features + old_mendonca.calcSymmetricConstraints(featureModel);
     
        System.setOut(tmpOut);
         
//      output = "Pre-CL-MinSpan";
//      output = output + "\t" + String.valueOf(ecr);
//      output = output + "\t" + featureModel.getName();
        output = String.valueOf(bdd_size) + "\t" + String.valueOf(reasoner.countValidConfigurations()) + "\t" +String.valueOf(reasoner.getHeuristicRunningTime()/1000);
        //output = output + "\t"+String.valueOf(featureModel.countFeatures());
        for( int i=0; i< order.length; i++){
            output = output + "\t" + order[i];
        }
        //System.out.println(reasoner.getBDD().toString());
//      output = output + "\t" + String.valueOf(totalfeatures); 
//      output = output + "\t" + String.valueOf(symmetric_features);
//      output = output + "\t" + String.valueOf(symmetric_features/totalfeatures*100);
         
        //reasoner.countValidConfigurations();
         
 
        System.out.println(output);
         
        //showFeatures(featureModel);
 
    }
     
    public static void showFeatures(FeatureModel _featureModel) {
        for( FeatureTreeNode node : _featureModel.getNodes() ) {
            System.out.println("Node:" + node.getID());         
        }
    }
     
    public static boolean isSolitaireFeature(FeatureTreeNode _node) {
         
        boolean ret=_node.getClass().getName().equals("splar.core.fm.SolitaireFeature");
         
        return ret;
    }
     
    public static boolean isGroupFeature(FeatureTreeNode _node) {
         
        boolean ret=_node.getClass().getName().equals("splar.core.fm.FeatureGroup");
         
        return ret;
    }
     
    public static int calcSymmetricConstraints(FeatureModel _featureModel ) {
        int ret=0;
        //Collections
        String pattern  = "(.*)not\\s+\\b(.+?)\\b\\s+or\\s+not\\s+\\b(.+?)(.*)";
        for(Iterator<PropositionalFormula> it =_featureModel.getConstraints().iterator();it.hasNext();){
            PropositionalFormula formula = it.next();
 
            String cleanClause = formula.getFormula();
            cleanClause = cleanClause.replaceAll("~", "not ");
            cleanClause = cleanClause.replaceAll("\\(", "");
            cleanClause = cleanClause.replaceAll("\\)", "");
            if (cleanClause.matches(pattern)) {
                //System.out.println(cleanClause);
                ret = ret + 1;
            }
 
             
        }
        //  _featureModel.getConstraints().iterator()
        //for(int i=0;i<_featureModel.getConstraints().size();i++){
        //  
        //}
     
        return ret;
    }
     
     
    public static int getFeaturesRemoved(FeatureTreeNode _featureTreeNode) {
        int ret = 0 ;
         
        if(isGroupFeature(_featureTreeNode)) {
            if(_featureTreeNode.getParent().getChildCount()==1) {
                ret  = ret + 1;
            }
        }
 
        for(int i=0;i<_featureTreeNode.getChildCount();i++){         
            FeatureTreeNode child = (FeatureTreeNode)_featureTreeNode.getChildAt(i);
            ret = ret + getFeaturesRemoved(child);
        }
 
             
         
        return ret;
    }
     
    public static Set<String> getSymmetricFeatures(FeatureTreeNode _featureTreeNode) {
        Set<String> ret = new HashSet<String>(); 
        TreeNode node;
        FeatureTreeNode child;
        FeatureTreeNode groupFeature;       
        splar.core.fm.SolitaireFeature solitaireFeature;
         
        if(isGroupFeature(_featureTreeNode)) {
            for(int j=0;j<_featureTreeNode.getChildCount();j++){ 
                groupFeature = (FeatureTreeNode)_featureTreeNode.getChildAt(j);
                 
                if (_featureTreeNode.getChildCount() == 1 && isSolitaireFeature(groupFeature) ) {
                    groupFeature.setID(groupFeature.getID());
                }
                ret.add(groupFeature.getID());                  
            }
        } else {
            if(isSolitaireFeature(_featureTreeNode) ){
                solitaireFeature = (splar.core.fm.SolitaireFeature) _featureTreeNode;
                if(!solitaireFeature.isOptional()){
                    ret.add(((FeatureTreeNode)_featureTreeNode.getParent()).getID());
                    ret.add(_featureTreeNode.getID());
                }
            }
        }
         
        for(int i=0;i<_featureTreeNode.getChildCount();i++){         
            node = _featureTreeNode.getChildAt(i);
            child = (FeatureTreeNode)node;
            ret.addAll(getSymmetricFeatures(child));
        }
         
         
        return ret;
    }
     
    public static FeatureTreeNode getParent(FeatureTreeNode _featureTreeNode){
        FeatureTreeNode ret = (FeatureTreeNode)_featureTreeNode.getParent();
        if(ret.getParent().getChildCount()==1) {
            ret = getParent(ret);
        }       
        return ret;     
    }
 
     
    public static int calcSymmetricFeatures(FeatureTreeNode _featureTreeNode,FeatureModel _featureModel) {
        int ret;
        Set<String> sym =getSymmetricFeatures(_featureTreeNode);
        ret = sym.size();
         
        return ret;
    }
     
    public static int calcGroupFeatures(FeatureTreeNode _featureTreeNode) {
        int ret=0;
        TreeNode node;
        if(isGroupFeature(_featureTreeNode)) {
            ret++;
        }
        for(int i=0;i<_featureTreeNode.getChildCount();i++){
            node = _featureTreeNode.getChildAt(i);
            ret = ret + calcGroupFeatures((FeatureTreeNode)node);           
        }
        return ret;
    }
 
 
}
